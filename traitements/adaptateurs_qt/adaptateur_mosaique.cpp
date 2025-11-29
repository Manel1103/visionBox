#include "adaptateur_mosaique.h"
#include "../core/mosaique.h"

#include <QSlider>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <opencv2/opencv.hpp>

// ------------------ Conversion QImage <-> Mat ------------------

static cv::Mat qImageToMat(const QImage &image)
{
    QImage img = image.convertToFormat(QImage::Format_RGBA8888);
    cv::Mat mat(img.height(), img.width(), CV_8UC4,
                const_cast<uchar*>(img.bits()), img.bytesPerLine());
    cv::Mat matBGR;
    cv::cvtColor(mat, matBGR, cv::COLOR_RGBA2BGR);
    return matBGR.clone();
}

