// Copyright 2019 Stellar Development Foundation and contributors. Licensed
// under the Apache License, Version 2.0. See the COPYING file at the root
// of this distribution or at http://www.apache.org/licenses/LICENSE-2.0

#pragma once

#include "herder/TxSetFrame.h"

namespace stellar
{

class SimulationTxSetFrame : public AbstractTxSetFrameForApply
{
    Hash const mNetworkID;
    Hash const mPreviousLedgerHash;
    std::vector<TransactionEnvelope> const mTransactions;
    std::vector<TransactionResultPair> const mResults;
    Hash const mContentsHash;

  public:
    SimulationTxSetFrame(Hash const& networkID, Hash const& previousLedgerHash,
                         std::vector<TransactionEnvelope> const& transactions,
                         std::vector<TransactionResultPair> const& results);

    int64_t getBaseFee(LedgerHeader const& lh) const override;

    Hash const& getContentsHash() override;

    Hash const& previousLedgerHash() const override;

    size_t sizeTx() const override;

    size_t sizeOp() const override;

    std::vector<TransactionFramePtr> sortForApply() override;
};
}
