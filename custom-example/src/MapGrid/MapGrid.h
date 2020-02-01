/****************************************************************************
 *
 *   (c) 2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include <QObject>
#include <QGeoCoordinate>
#include <QThread>

#include "MapGridMGRS.h"

class MapGrid : public QObject
{
    Q_OBJECT
public:
    explicit MapGrid(QObject* mapGridQML);

    Q_INVOKABLE void geometryChanged(double zoomLevel, const QGeoCoordinate& topLeft, const QGeoCoordinate& topRight,
                                     const QGeoCoordinate& bottomLeft, const QGeoCoordinate& bottomRight,
                                     int viewportWidth, int viewportHeight);

public slots:
    void updateValues(const QVariant& values);

signals:
    void geometryChangedSignal(double zoomLevel, const QGeoCoordinate& topLeft, const QGeoCoordinate& topRight,
                               const QGeoCoordinate& bottomLeft, const QGeoCoordinate& bottomRight,
                               int viewportWidth, int viewportHeight);

private:
    QObject* _mapGridQML = nullptr;
    MapGridMGRS* _mapGridMGRS = nullptr;
    QThread* _mapGridThread = nullptr;
    bool _calculationRunning = false;
    bool _calculationPending = false;
    double _pendingZoomLevel;
    QGeoCoordinate _pendingTopLeft;
    QGeoCoordinate _pendingTopRight;
    QGeoCoordinate _pendingBottomLeft;
    QGeoCoordinate _pendingBottomRight;
    int _pendingViewportWidth;
    int _pendingViewportHeight;
};
