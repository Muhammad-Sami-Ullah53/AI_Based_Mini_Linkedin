#ifndef MATCHINGENGINE_H
#define MATCHINGENGINE_H

#include "Candidate.h"
#include "Job.h"

class MatchingEngine
{
public:


double calculateEducationMatch(
    const Candidate& candidate,
    const Job& job
);
    double calculateSkillMatch(
        const Candidate& candidate,
        const Job& job
    );

    double calculateExperienceMatch(
        const Candidate& candidate,
        const Job& job
    );

    double calculateOverallScore(
        const Candidate& candidate,
        const Job& job
    );
};

#endif