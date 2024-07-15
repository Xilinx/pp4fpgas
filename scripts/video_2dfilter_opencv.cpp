#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void zeroOutEdges(cv::Mat& image) {
    // Assuming image is a valid cv::Mat object
    int thickness = 1; // Thickness of the edge to be zeroed out

    // Set top edge to zero
    cv::rectangle(image, cv::Point(0, 0), cv::Point(image.cols, thickness - 1), cv::Scalar(0, 0, 0), cv::FILLED);

    // Set bottom edge to zero
    cv::rectangle(image, cv::Point(0, image.rows - thickness), cv::Point(image.cols, image.rows), cv::Scalar(0, 0, 0), cv::FILLED);

    // Set left edge to zero
    cv::rectangle(image, cv::Point(0, 0), cv::Point(thickness - 1, image.rows), cv::Scalar(0, 0, 0), cv::FILLED);

    // Set right edge to zero
    cv::rectangle(image, cv::Point(image.cols - thickness, 0), cv::Point(image.cols, image.rows), cv::Scalar(0, 0, 0), cv::FILLED);
}

void applyCustom2DFilter(const Mat& inputImage, Mat& outputImage) {
    // Define the kernel. Note that OpenCV expects a floating point matrix for the filter2D function.
    Mat kernel = (Mat_<float>(3,3) << 1, 2, 1,
                                       2, 4, 2,
                                       1, 2, 1);
    // Normalize the kernel to ensure the brightness of the output image is similar to the input image.
    kernel = kernel / 16.0;

    // Apply the custom 2D filter
    filter2D(inputImage, outputImage, -1, kernel);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <InputImage> <OutputImage>" << endl;
        return -1;
    }

    // Read the image file
    Mat image = imread(argv[1]);
    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    Mat filteredImage;
    applyCustom2DFilter(image, filteredImage);

    // Zero out the edges of the filtered image
    // This is done to ignore any differences in the edges of the images
    // The opencv 2d filter can filter up to the edge of the image.  The HLS
    // Book example skips this edge case.
    //
    zeroOutEdges(filteredImage);

    // Write the filtered image to disk
    bool writeSuccess = imwrite(argv[2], filteredImage);
    if (!writeSuccess) {
        cout << "Failed to write the image" << endl;
        return -1;
    }

    cout << "Image processed and saved successfully" << endl;
    return 0;
}