/*
 * This file is part of Gen4IDs
 * Copyright (C) 2018-2020 by Admiral_Fish
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef IDSEARCHER_HPP
#define IDSEARCHER_HPP

#include <QMutex>
#include <QThread>
#include <QVector>
#include <Core/IDResult.hpp>

class IDSearcher : public QThread
{
    Q_OBJECT
public:
    IDSearcher(const QVector<uint16_t> &tidFilter, const QVector<uint16_t> &sidFilter, uint32_t minDelay, uint32_t maxDelay, bool infinite,
               uint64_t maxProgress);
    void run() override;
    int currentProgress() const;
    QVector<IDResult> getResults();

public slots:
    void cancelSearch();

private:
    QVector<uint16_t> tidFilter;
    QVector<uint16_t> sidFilter;
    uint32_t minDelay;
    uint32_t maxDelay;
    bool infinite;

    QVector<IDResult> results;
    QMutex mutex;
    bool cancel;
    uint64_t progress;
    uint64_t maxProgress;

    uint32_t getID(uint32_t seed);
};

#endif // IDSEARCHER_HPP
