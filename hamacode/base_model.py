#!/usr/bin/python3
from uuid import uuid4
from datetime import datetime


class BaseModel:
"class basemodel"
    def __init__(self *args ,**kwargs):
        """new basemodel.
        Args:
            *args:multi argument 
            **kwargs:dictionnary
        """
    self.id = str(uuid4())
    self.created_at = datetime.today()
    self.updated_at = datetime.today()

    def __str__(self):
        """return signification of the class,user,dic"""
        classe_name = self.__class__.__name__
        return "[] () <>".format (class_name , self.id, self.__dict__)

    def save(self):
        """update the public instance attribute withe the current dattime"""
        self.updated_at = datetime.today()

    def to_dict(self):
        """returns a dictionary containing all keys/values"""
        rdd = self.__dict__.copy()
        rdd["created_at"] = self.created_at.isoformat()
        rdd["updated_at"] = self.updated_at.isoformat()
        rdd["__class__"] = self.__class__.__name__
        return rdd
