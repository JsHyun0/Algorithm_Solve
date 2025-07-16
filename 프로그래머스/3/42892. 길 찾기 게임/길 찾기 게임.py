### 1. Python Class Sort
#### - Using sorted() function with lambda
#### - reverse option -> descent

### 2. Python call by ref
#### - Mutable data는 call by ref으로 호출된다.

### 3. Python stack overflow...
import sys
sys.setrecursionlimit(10**6)
### Recursion limit을 늘려준다.
class Node:
    def __init__(self,num, x, y, level=-1):
        self.num = num
        self.x = x
        self.y = y
        
        
def split(nodes, pre, post):
    if not nodes:
        return None
    top = -1
    root = None
    # 가장 y가 큰 노드가 루트
    root = max(nodes, key=lambda n: n.y)
    root_idx = nodes.index(root)
    
    pre.append(root.num)
    left_nodes = nodes[:root_idx]
    right_nodes = nodes[root_idx+1:]
    split(nodes[:root_idx], pre, post)
    split(nodes[root_idx+1:], pre, post)
    post.append(root.num)
    return
  

def solution(nodeinfo):
    pre_ = []
    post_ = []
    nodes = []
    for idx in range(len(nodeinfo)):
        x, y = nodeinfo[idx]
        node = Node(idx+1,x,y)
        nodes.append(node)
    nodes = sorted(nodes, key=lambda node : node.x)

    tmp = split(nodes, pre_, post_)
            
    ##
    ## 여기서 리스트 좌우는 각각 서브트리가 된다.

    answer = [pre_, post_]
    return answer