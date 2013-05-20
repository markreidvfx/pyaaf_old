import yaml

from pprint import pprint


class Node(object):
    
    def __init__(self):
        self.parent = None
        self.name = "Root"
        self.children = []
        
        
    def get_parent(self):
        
        path = []
        
        item = self.parent

        while item:
            if item.name != "Root":
                path.append(item.name)
            item = item.parent
        
        return path
    
    def get_all_children(self):
        
        children = []
        
        
        walk_children(children,self)
        
        return children
    
    def __repr__(self):
        return self.name



def walk_children(main_list, node):
    
    for item in node.children:
        
        main_list.append(item.name)
        
        walk_children(main_list,item)
        

def walk_dict(registry,base,data):

    for key, value in data.items():
        name = key.replace("Ax",'')
        n = Node()
        n.parent = base
        n.name = name
        base.children.append(n)
        
        registry[name] = n
        if isinstance(value,dict):
            walk_dict(registry, n,value)
            

def get_hierachy():
    f = open("hierarchy.yml")
    s = f.read()
    f.close()
    d = yaml.load(s)
    
    #pprint(d)
    
    root = Node()
    
    registry = {}
    
    walk_dict(registry,root, d)
    
    return registry
    



if __name__ == "__main__":
    #f = open("hierarchy.yml")
    #s = f.read()
    #f.close()
    
    
   #d = yaml.load(s)
    
    #pprint(d)
    
    #root = Node()
    
    registry = get_hierachy()
    
    #walk_dict(registry,root, d)
    
    for key,value in sorted(registry.items()):
        print "name:",key
        print 'parents:', value.get_parent()
        print 'children:',value.get_all_children()