#ifndef SUBJOB_HPP
#define SUBJOB_HPP

#include <list>
#include <mutex>
#include <atomic>

#include "parlex/details/fast_match.hpp"
#include "parlex/details/permutation.hpp"
#include "parlex/details/context.hpp"
#include "parlex/details/producer.hpp"

namespace parlex {
namespace details {

class job;
class state_machine_base;

class subjob : public producer {
public:
	state_machine_base const & machine;
	forward_list_c<context> contexts;
	std::list<permutation> queuedPermutations;
	std::mutex mutex;
	std::atomic<int> lifetimeCounter;

	subjob(job & owner, state_machine_base const & machine, int const documentPosition);
	subjob(subjob const & other) = delete;
	virtual ~subjob();

	void start();
	context_ref construct_stepped_context(context_ref const & prior, fast_match const & fromTransition);
	void on(context_ref const & c, recognizer const & r, int nextDfaState, behavior::leaf const * leaf);
	void accept(context_ref const & c);
	// for special use by the parser to seed the queue
	context_ref construct_start_state_context(int documentPosition);
	void end_dependency();
	void finish_creation();
	void decrement_lifetime();
	void increment_lifetime();
	void flush();
};

} // namespace details
} // namespace parlex

#endif //SUBJOB_HPP
