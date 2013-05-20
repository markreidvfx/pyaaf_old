import yaml

from pprint import pprint


class Node(object):
    
    def __init__(self):
        self.parent = None
        self.name = "Root"
        self.children = []
        self.alt_name = None
        self.has_ver2 = False
        self.has_ver3 = False
        
    def set_name(self, name):
        
        self.name = name
        
        if name in ('KLVDataDefinition', 'TaggedValueDefinition', 'TypeDefObjectRef'):
            self.alt_name = name.replace('Definition','Def').replace('Object','Obj')
        
        if name in ('CompositionMob','MasterMob'):
            pass
            
        if name in ('CompositionMob',
                    'MasterMob',
                    'Component',
                    'DataDef',
                    'Dictionary',
                    'Header',
                    'Mob',
                    'RGBADescriptor',
                    'TimelineMobSlot',
                    ):
            self.has_ver2 = True
            
        if name in ('DataDef'):
            self.has_ver3 = True
        
    def get_parent(self):
        
        path = []
        
        item = self.parent

        while item:
            if item.name != "Root":
                path.append(item.name)
            item = item.parent
        
        return path
    
    def get_all_children(self,include_extra=False):
        
        children = []
        
        
        walk_children(children,self,include_extra)
        
        return children
    
    def __repr__(self):
        return self.name



def walk_children(main_list, node,include_extra=False):
    
    for item in node.children:
        
        main_list.append(item.name)
        
        if include_extra:
            if item.has_ver2:
                main_list.append(item.name + "2")
            if item.has_ver3:
                main_list.append(item.name + "3")
        
        walk_children(main_list,item)
        

def walk_dict(registry,base,data):

    for key, value in data.items():
        name = key.replace("Ax",'')
        n = Node()
        n.parent = base
        n.set_name(name)
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