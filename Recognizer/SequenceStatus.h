#pragma once 

namespace SequenceStatus
{
    enum SequenceStatus
    {
        Accepted,
        Rejected,
        Unidentified
    };
#if _DEBUG
    const vector<string> toString =
    {
        "Accepted",
        "Rejected",
        "Unidentified"
    };
#endif
}