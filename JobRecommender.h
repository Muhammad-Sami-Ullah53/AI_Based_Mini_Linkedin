#ifndef JOBRECOMMENDER_H
#define JOBRECOMMENDER_H

#include "Candidate.h"
#include "Job.h"
#include "MatchingEngine.h"

class JobRecommender
{
public:

    void recommendJobs(
    const Candidate& candidate,
    Job* jobs,
    int jobCount,
    int appliedJobId
);
};

#endif