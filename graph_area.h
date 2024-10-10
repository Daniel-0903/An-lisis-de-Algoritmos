/* CAMBIO 9/10
#ifndef GRAPH_AREA_H
#define GRAPH_AREA_H

#include <gtkmm/drawingarea.h>
#include <vector>
#include <string>

class GraphArea : public Gtk::DrawingArea {
public:
	GraphArea(const std::vector<double>& data, const std::string& title);
	virtual ~GraphArea() {}
	
protected:
		bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
		
private:
	std::vector<double> data;
	std::string title;
	double max_value;
	void draw_axes(const Cairo::RefPtr<Cairo::Context>& cr);
	void draw_graph(const Cairo::RefPtr<Cairo::Context>& cr);
};

#endif // GRAPH_AREA_H
*/
