#------------------------------------------------------------------------
# Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
#
# This file is part of PowerGrid.
#
# PowerGrid is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# PowerGrid is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
#------------------------------------------------------------------------

#------------------------------------------------
#
# Global qmake project file for PowerGrid.
#
# This project file includes and builds each
# subproject and links all modules together.
#
#------------------------------------------------

TARGET = PowerGrid
TEMPLATE = subdirs

SUBDIRS += JACE UserInterface #PluginFramework DefaultPlugin

UserInterface.depends = JACE
#DefaultPlugin.depends = PluginFramework
