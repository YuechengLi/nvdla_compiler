#include "net.h"
#include "net_parser.h"
#include "memory_list_parser.h"
#include "symbol_list_parser.h"
using namespace nvdla;
int main()
{
    nvdla::NetParser lenet;

    lenet.load_caffe_net("lenet.param","lenet.bin");
    lenet.build_nvdla_net();
    TaskListParser* tlp = new TaskListParser(&lenet);
    tlp->buildList(); 
    MemoryListParser* memlist = new MemoryListParser(&lenet, tlp);
    memlist->buildList();
    memlist->fillTaskAddrList();
    tlp->debugTaskList();    
    memlist->debugMemList();
    SymbolListParser* symbollist = new SymbolListParser(&lenet,memlist,tlp);
    symbollist->buildList();
    symbollist->dump_blobs_info();
    return 0;
}
