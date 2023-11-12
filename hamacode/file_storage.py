#!/user/bin/python3 

import json

class FileStorage:
    """serializes ins to a JSON file and deserializes JSON file to ins"""
    __file_path = "file.json"
    __objects = {}

    def all(self):
        """Return the dictionary __objects."""
        return FileStorage.__objects

    def new(self, obj):
        """Set in __objects obj with key <obj_class_name>.id"""
        name = obj.__class__.__name__
        FileStorage.__objects["{}.{}".format(name, obj.id)] = obj

    def save(self):
        """serializes __objects to the JSON file """




