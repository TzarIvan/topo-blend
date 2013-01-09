#ifndef LANDMARKS_DIALOG_H
#define LANDMARKS_DIALOG_H

#include <QDialog>
#include "topo-blend.h"

namespace Ui {
class LandmarksDialog;
}

class LandmarksDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit LandmarksDialog(topoblend *topo_blender, QWidget *parent = 0);
    ~LandmarksDialog();

private:
	topoblend *tp;
	GraphCorresponder *gcorr;
	Ui::LandmarksDialog *ui;

public:
	Structure::Graph * sg();
	Structure::Graph * tg();
	bool sIsLandmark(int i);
	bool tIsLandmark(int i);
	Structure::Node* sNode(int i);
	Structure::Node* tNode(int i);

	void updateSList();
	void updateTList();
	void updateLandmarksTableWidget();
	void updateLandmarksTab();

	void updateCorrTableWidget();	
	void updateCorrTab();
	void updateAll();

public slots:
	// Landmarks
	void sClearSelections();
	void tClearSelections();
	void visualizeSelections();
	void visualizeLandmark();

	void addLandmark();
	void removeLandmark();

	void saveLandmarks();
	void loadLandmarks();

	// Alignment
	void showAABB(int state);
	void rotateGraph();

	// Correspondences
	void reload();
	void visualizePart2PartDistance(int id);
	void computeCorrespondences();
};

#endif // LANDMARKS_DIALOG_H