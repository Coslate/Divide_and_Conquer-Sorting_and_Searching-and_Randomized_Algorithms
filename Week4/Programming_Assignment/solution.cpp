//solution.cpp
#include <solution.h>

void buildEdgeInfo(std::unordered_map<std::string, LinkedListNode*> &map_node_st2lln, const std::vector<std::vector<std::string>> &input_edge_list, std::unordered_set<StrPair> &total_edge, std::vector<StrPair> &total_edge_v, std::unordered_set<std::string> &total_node){
    //Build the mapping of node_name -> address for all nodes.
    for (auto &itRow : input_edge_list){
        for (size_t i=0; i<itRow.size();++i){
            if(map_node_st2lln.find(itRow[i]) == map_node_st2lln.end()){//not found
                LinkedListNode* new_node = new LinkedListNode(0, itRow[i]);
                map_node_st2lln[itRow[i]] = new_node;
                total_node.insert(itRow[i]);
            }

            if(i != 0){
                //adj_list.SetAdjList(map_node_st2lln[itRow[0]], map_node_st2lln[itRow[i]], 0);

                StrPair tmp_edge(itRow[0], itRow[i]);
                StrPair tmp_edge_inv(itRow[i], itRow[0]);
                if((total_edge.find(tmp_edge) == total_edge.end()) && (total_edge.find(tmp_edge_inv) == total_edge.end())){
                    total_edge.insert(tmp_edge);
                    total_edge_v.push_back(tmp_edge);
                }
            }
        }
    }
}

inline void getRandomEdge(std::unordered_set<StrPair> &total_edge, StrPair &out_str){
    int rand_idx = (rand() % total_edge.size()) + 0;
    int count = 0;

    for(const auto &elem: total_edge){
        if(count == rand_idx){
            out_str = elem;
            break;
        }
        ++count;
    }
}

inline void getRandomEdge(const std::vector<StrPair> &total_edge, StrPair &out_str){
    int rand_idx = (rand() % total_edge.size()) + 0;
    out_str = total_edge[rand_idx];
}

inline void unionFindInitialization(UnionFind &uf_node_set, const std::unordered_set<std::string> &total_node, std::unordered_map<std::string, LinkedListNode*> &map_node_st2lln){
    for(const auto &elem : total_node){
        uf_node_set.FindIterative(map_node_st2lln[elem]);
    }
}

void kargerRandomContraction(const int &trial_num, const std::vector<StrPair> &total_edge, const std::unordered_set<std::string> &total_node, std::unordered_map<std::string, LinkedListNode*> &map_node_st2lln, std::unordered_map<int, int> &map_cut2num, int &min_cut_edge){
    int count = 0;
    while(count < trial_num){
        std::cout<<"progress = "<<count/(double)trial_num * 100<<"%"<<std::endl;
        UnionFind uf_node_set;
        int count_min_cut_edge = 0;
        int total_node_size = total_node.size();

        unionFindInitialization(uf_node_set, total_node, map_node_st2lln);

        while(total_node_size > 2){
            StrPair out_str;
            getRandomEdge(total_edge, out_str);
            if(uf_node_set.Union(map_node_st2lln[out_str.first], map_node_st2lln[out_str.second])){
                --total_node_size;
            }
        }

        //Calculate the crossing edge.
        for(const auto &remained_edge : total_edge){
            if(uf_node_set.FindIterative(map_node_st2lln[remained_edge.first]) != uf_node_set.FindIterative(map_node_st2lln[remained_edge.second])){
                ++count_min_cut_edge;
            }
        }

        if(map_cut2num.find(count_min_cut_edge) == map_cut2num.end()){
            map_cut2num[count_min_cut_edge] = 1;
        }else{
            map_cut2num[count_min_cut_edge] += 1;
        }

        if(min_cut_edge > count_min_cut_edge){
            min_cut_edge = count_min_cut_edge;
        }
        ++count;
    }
}
