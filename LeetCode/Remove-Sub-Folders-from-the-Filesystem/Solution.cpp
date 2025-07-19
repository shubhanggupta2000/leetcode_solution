class TNode:
    def __init__(self):
        self.children = defaultdict(TNode)
        self.leaf = False

class Solution:
    def removeSubfolders(self, folders: List[str]) -> List[str]:
        self.root = TNode()
        # populate the trie
        for folder in folders:
            node = self.root
            subs = folder.split('/')
            for sub in subs:
                if sub == '':
                    continue
                node = node.children[sub]
                # optimization 1: when building, if the node is already a leaf, 
                # we can break early since we know that the current folder is 
                # a sub-folder
                if node.leaf:
                    break
            node.leaf = True
        
        # generate non-subfolders 
        # optimization 2: traverse the trie via bfs. if we discover the node is a leaf, 
        # stop bfs on it and add it to the output
        path = []
        q = deque([('', self.root)])
        while q:
            directory, node = q.popleft()

            for sub, child in node.children.items():
                if child.leaf:
                    path.append(directory+'/'+sub)
                    continue
                
                q.append((directory+'/'+sub, child))
        
        return path