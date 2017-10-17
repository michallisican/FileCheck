#include "iSearching.h"
#include "SearchingParallel.h"
#include "SearchingSequential.h"
#include "SearchingFactory.h"


std::shared_ptr<iSearching> SearchingFactory::SearchType(int methode, int type)
{
	if (type == parallel_t)
		return std::make_shared<SearchingParallel>(methode, type);
	else if (type == sequential_t )
		return std::make_shared<SearchingSequential>(methode, type);
	else
	{
		throw std::exception("SearchingFactory::SearchType: type not found!!!\n");
		return nullptr;
	}
}
