#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <iostream>
#include <vector>

class Particle {
	private:
		Vector pva;

		std::string type; // e.g. electron, proton etc.
		int type_num;
		std::string group; // e.g. hadron, meson etc.
		double mass; // kilogram
		double charge; // coulomb
		int lepton_num;
		double baryon_num;

		int instanceid;

		std::vector<Particle> components;

	public:
		Particle() {}
		Particle(std::string  t, int tn, std::string g, double m, double c, int ln, double bn) {
			type = t;
			type_num = tn;
			group = g;
			mass = m;
			charge = c;
			lepton_num = ln;
			baryon_num = bn;
		}

		void setComponents(std::vector<Particle> c) { components = c; }
		std::vector<Particle> getComponents() { return components; }

		void setPosition(std::vector<double> pos) { pva.setPosition(pos); }
		std::vector<double> getPosition() { return pva.getPosition(); }

		void setVelocity(std::vector<double> vel) { pva.setVelocity(vel); }
		std::vector<double> getVelocity() { return pva.getVelocity(); }

		void setAcceleration(std::vector<double> acc) { pva.setAcceleration(acc); }
		std::vector<double> getAcceleration() { return pva.getAcceleration(); }

		// mechanical methods
		void updateVector(double time_elapsed) {}
		std::vector<double> resultantForce(std::vector<Particle> particles) {}
		std::vector<double> gravitationalForce(Particle p) {
			// F = (G * mass_1 * mass_2) / (dist ^2)
			// F = G * ((m1 * m2) / r^2)
			double G = 6.6741e-11;
			std::vector<double> forces = { 0, 0, 0 };

			double dist;

			std::vector<double> distance = { 0, 0, 0 };

			std::vector<double> p_pos = p.getPosition();

			

			/*for (int i = 0; i  < 3; i++) {
				distance[i] = abs()
				
			}*/
			
		}
		std::vector<double> electromagneticForce() { return {0, 0, 0}; }
		std::vector<double> weakNuclearForce() { return {0, 0, 0}; }
		std::vector<double> strongNuclearForce() { return {0, 0, 0}; }
};

#endif