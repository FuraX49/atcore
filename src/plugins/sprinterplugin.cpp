/* AtCore KDE Libary for 3D Printers
    Copyright (C) <2016>

    Authors:
        Tomaz Canabrava <tcanabrava@kde.org>
        Chris Rizzitello <rizzitello@kde.org>
        Patrick José Pereira <patrickelectric@gmail.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <QString>
#include <QLoggingCategory>

#include "sprinterplugin.h"
#include "temperature.h"
#include "atcore.h"

QString SprinterPlugin::_ok = QStringLiteral("ok");

Q_LOGGING_CATEGORY(SPRINTER_PLUGIN, "org.kde.atelier.core.firmware.sprinter");

QString SprinterPlugin::name() const
{
    return QStringLiteral("Sprinter");
}

SprinterPlugin::SprinterPlugin()
{
    qCDebug(SPRINTER_PLUGIN) << name() << " plugin loaded!";
}

void SprinterPlugin::validateCommand(const QString &lastMessage)
{
    if (lastMessage.contains(_ok)) {
        emit readyForCommand();
    }
}

QByteArray SprinterPlugin::translate(const QString &command)
{
    return command.toLocal8Bit();
}

