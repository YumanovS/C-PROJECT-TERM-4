from distutils.core import setup, Extension

module1 = Extension(
	'slausolve', 
	 sources = ['slausolve.c'] 
)

setup(
	name = 'slausolve',              
	version = '1.1',             
	description = 'That module solve the slau', 
	ext_modules= [module1]
)