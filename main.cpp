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

#include <QApplication>
#include <Forms/MainWindow.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Gen 4 IDs");
    a.setOrganizationName("Gen 4 IDs Team");

    MainWindow w;
    w.show();

    return a.exec();
}
