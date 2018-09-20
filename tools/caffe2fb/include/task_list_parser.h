/*
 * task_list_parser.h
 *
 *  Created on: Sep 18, 2018
 *      Author: jiqianxiang
 */

#ifndef TASK_LIST_PARSER_H_
#define TASK_LIST_PARSER_H_

#include "list_entry_parser.h"

namespace nvdla {

class TaskListParser: public ListEntryParser {
public:
	TaskListParser();
	virtual ~TaskListParser();

	void  buildList();
	void* getList() const;

protected:
	std::vector<NvU16> get_task_id() const {
		std::vector<NvU16> task_ids;
		for (ILoadable::TaskListEntry& task : mList)
			task_ids.push_back(task.id);
		return task_ids;
	}
	friend class SubmitListParser;

private:
	std::vector<ILoadable::TaskListEntry> mList;

};

} /* namespace nvdla */

#endif /* TASK_LIST_PARSER_H_ */