# include <iostream>
using namespace std;

class Vector {
	private:
		vector<double> position, velocity, acceleration;

	public:
		Vector() {
			position     = { -1, -1, -1 };
			velocity     = { -1, -1, -1 }; 
			acceleration = { -1, -1, -1 };
		}

		// these methods don't do any checking in regards to len of vector p, v and a
		// don't pass in bad arguments
		void updatePosition(double time_elapsed) {
			// old velocity values 
			vector<double> unupdated = velocity;
			// updated velocity values
			updateVelocity(time_elapsed);

			for (int i = 0; i < 3; i++) {
				// area under triangle = (b * h) / 2
				// base: time_elapsed
				// height: updated velocity - unupdated velocity
				position[i] += (time_elapsed * (velocity[i] + unupdated[i])) / 2;
			}
		}
		void updateVelocity(double time_elapsed) {
			// v = u + at  --> v += at
			for (int i = 0; i < 3; i++) {
				velocity[i] += acceleration[i] * time_elapsed;
			}
		}
		void updateAcceleration(double mass, vector<double> newtons) {
			//f = ma -> a = f/m
			for (int i = 0; i < 3; i++) {
				acceleration[i] = newtons[i] / mass;
			}
		}

		void setPosition(vector<double> p) { position = p; }
		vector<double> getPosition() { return position; }

		void setVelocity(vector<double> v) { velocity = v; }
		vector<double> getVelocity() { return velocity; }

		void setAcceleration(vector<double> a) { acceleration = a; }
		vector<double> getAcceleration() { return acceleration; }

};

class Particle {
	private:
		Vector pva;

		string type; // e.g. electron, proton etc.
		int type_num;
		string group; // e.g. hadron, meson etc.
		double mass; // kilogram
		double charge; // coulomb
		int lepton_num;
		double baryon_num;

		int instanceid;

		vector<Particle> components;

	public:
		Particle(string  t, int tn, string g, double m, double c, int ln, double bn) {
			type = t;
			type_num = tn;
			group = g;
			mass = m;
			charge = c;
			lepton_num = ln;
			baryon_num = bn;
		}

		void setComponents(vector<Particle> c) { components = c; }
		vector<Particle> getComponents() { return components; }

		void setPosition(vector<double> pos) { pva.setPosition(pos); }
		vector<double> getPosition() { return pva.getPosition(); }

		void setVelocity(vector<double> vel) { pva.setVelocity(vel); }
		vector<double> getVelocity() { return pva.getVelocity(); }

		void setAcceleration(vector<double> acc) { pva.setAcceleration(acc); }
		vector<double> getAcceleration() { return pva.getAcceleration(); }

		// mechanical methods
		void updateVector(double time_elapsed) {}
		vector<double> resultantForce(vector<Particle> particles) {}
		vector<double> gravitationalForce(Particle p) {
			// F = (G * mass_1 * mass_2) / (dist ^2)
			// F = G * ((m1 * m2) / r^2)
			double G = 6.6741e-11;
			vector<double> forces = { 0, 0, 0 };

			double dist;

			vector<double> distance = { 0, 0, 0 };

			vector<double> p_pos = p.getPosition();

			

			/*for (int i = 0; i  < 3; i++) {
				distance[i] = abs()
				
			}*/
			
		}
		vector<double> electromagneticForce() {}
		vector<double> weakNuclearForce() {}
		vector<double> strongNuclearForce() {}
};

void listMenu(vector<string> choices) {
	for (int i = 0; i < choices.size();  i++) {
		cout << i + 1 << ": " << choices[i] << endl;
	}
}

int getChoice() { return 0; }
vector<int> getChoices() { return { 0, 0 }; }



int main() {
	cout << "Particle Simulation II" << endl;

	/*Vector vec;

	vector<double> p, v, a;

	p = vec.getPosition();
	v = vec.getVelocity();
	a = vec.getAcceleration();

	for (int i = 0; i < p.size(); i++) { cout << p[i] << " "; }
	cout << endl;
	for (int i = 0; i < v.size(); i++) { cout << v[i] << " "; }
	cout << endl;
	for (int i = 0; i < a.size(); i++) { cout << a[i] << " "; }
	cout << endl << endl;

	vector<double> v1 = { 0, 1, 2, 3 };

	vector<double> v2 = v1;
	v2[1] *= 2;
	v2[3] *= 2;

	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << "	" << v2[i] << endl;
	}*/

	vector<string> programs = { 
		"Create New Simulation", 
		"Load & Run Simulation",
	};
	cout << endl;
	listMenu(programs);

	
	return 0;
};
