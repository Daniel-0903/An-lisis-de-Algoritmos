#include "graph_area.h"
#include <gtkmm.h>
#include <cmath>
#include <algorithm>

GraphArea::GraphArea(const std::vector<double>& data, const std::string& title)
	: data(data), title(title), max_value(*std::max_element(data.begin(), data.end())) {}

bool GraphArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
	draw_axes(cr);
	draw_graph(cr);
	return true;
}

void GraphArea::draw_axes(const Cairo::RefPtr<Cairo::Context>& cr) {
	// Dibujar ejes
	cr->set_line_width(2.0);
	cr->set_source_rgb(0, 0, 0);  // Color negro
	cr->move_to(50, 20);          // Eje Y
	cr->line_to(50, 380);         // Desde el margen superior hasta el inferior
	cr->line_to(600, 380);        // Eje X
	cr->stroke();
	
	// Etiqueta del gráfico
	cr->set_source_rgb(0, 0, 0);
	cr->select_font_face("Sans", Cairo::FONT_SLANT_NORMAL, Cairo::FONT_WEIGHT_BOLD);
	cr->set_font_size(14);
	cr->move_to(300, 10);
	cr->show_text(title);
	
	// Etiquetas de los ejes
	cr->move_to(20, 200);
	cr->show_text("Tiempo (s)");
	
	cr->move_to(300, 400);
	cr->show_text("N (Tamaño de los datos)");
}

void GraphArea::draw_graph(const Cairo::RefPtr<Cairo::Context>& cr) {
	// Dibujar los puntos y la línea
	cr->set_line_width(1.5);
	cr->set_source_rgb(0, 0, 1);  // Azul para la gráfica
	
	double x_spacing = 500.0 / data.size();  // Espacio entre puntos
	double y_scale = 300.0 / max_value;      // Escalar el valor máximo al tamaño del área gráfica
	
	cr->move_to(50, 380 - data[0] * y_scale);
	for (size_t i = 1; i < data.size(); ++i) {
		cr->line_to(50 + i * x_spacing, 380 - data[i] * y_scale);
	}
	cr->stroke();
	
	// Dibujar los puntos
	cr->set_source_rgb(1, 0, 0);  // Rojo para los puntos
	for (size_t i = 0; i < data.size(); ++i) {
		cr->arc(50 + i * x_spacing, 380 - data[i] * y_scale, 3, 0, 2 * M_PI);
		cr->fill();
	}
}
