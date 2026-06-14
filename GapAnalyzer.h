#ifndef GAPANALYZER_H
#define GAPANALYZER_H

#include "Candidate.h"
#include "Job.h"

class GapAnalyzer
{
public:

    void findMissingSkills(
        const Candidate& candidate,
        const Job& job
    ) const;

    void analyzeExperienceGap(
        const Candidate& candidate,
        const Job& job
    ) const;
};

#endif