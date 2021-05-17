import os
import torch
import torchvision
import torchvision.transforms as tf
import argparse
import shutil
import tqdm
import numpy as np
import matplotlib.pyplot as plt
from class_names import CLASS_NAMES

IMAGE_EXT = ('.png', '.jpg')

def main(folder_path: str = 'new', threshold: float = 0.1):

	folder_path = os.path.abspath(folder_path)
	model = torchvision.models.resnet18(pretrained = True)
	images, images_paths = get_images(folder_path)
	classes = classify(model, images, threshold)
	move_images(classes, images_paths, folder_path)


def get_images(folder_path: str = 'new') -> tuple:
	'''Load images into np.arrays from folder_path

	   Arguments:
	   folder_path: str - path to folder with unclassified images

	   Returns:
	   images: list - list of images
	'''

	images_paths = [os.path.join(folder_path, image_path) for image_path in os.listdir(folder_path) if os.path.splitext(image_path)[-1] in IMAGE_EXT]
	images = [plt.imread(image_path) for image_path in images_paths]

	return (images, images_paths)

def classify(model: torch.nn.Module, images: list, threshold: float = 0.1) -> list:
	'''Classifies images to move them into
	   the appropriate folders later

	   Arguments:
	   model: torch.nn.Module - predicting neural network
	   images: list - list of numpy arrays

	   Returns:
	   output: list - list of classes, assigned to each image
	'''

	batch = batchify(images)

	model.eval()
	with torch.no_grad():
		predictions = model(batch)

	classes = [torch.argmax(pred).item() if torch.argmax(pred).item() > threshold 
										else 'other'
										for pred in predictions]

	return classes

def batchify(images: list) -> torch.Tensor:
	'''Turns list of images into pytorch batch

		Arguments:
		images: list - list of numpy arrays

		Returns:
		batch: torch.Tensor - tensor of shape (N, C, H, W)
	'''

	transform = tf.Compose([tf.ToPILImage(), tf.Resize((224, 224)), tf.ToTensor(), tf.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])])
	batch = torch.stack([transform(np.uint8(image[:,:,:-1])) 
									if image.shape[-1] > 3
									else transform(np.uint8(image))
									for image in images])

	return batch

def move_images(classes: list, images_paths: list, folder_path: str):
	'''Move images to folders according to assigned classes'''

	sorted_dir_path = os.path.join(os.path.split(folder_path)[0], 'data')
	os.makedirs(sorted_dir_path, exist_ok = True)
	for img_class, img_path in tqdm.tqdm(zip(classes, images_paths)):
		os.makedirs(os.path.join(sorted_dir_path, CLASS_NAMES[img_class]), exist_ok = True)
		shutil.move(img_path, os.path.join(sorted_dir_path, CLASS_NAMES[img_class]))

if __name__ == '__main__':

	parser = argparse.ArgumentParser()
	parser.add_argument('-fp', type = str, default = '../inception/data/user/like_image/new', help = 'Path to a folder with unclassified images')
	parser.add_argument('-th', type = float, default = 0.1, help = 'Threshold for class \'other\'')
	args = parser.parse_args()
	arguments = [arg for arg in dict(vars(args)).values()]

	main(*arguments)
