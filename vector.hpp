#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>

class Vector {
	private:
		std::vector<double> position, velocity, acceleration;

	public:
		Vector() {}
		Vector(std::vector<double> p, std::vector<double> v, std::vector<double> a) {
			// this doesn't enforce 3 dimensionality
			position = p;
			velocity = v;
			acceleration = a;
        }

		// these methods don't do any checking in regards to len of vector p, v and a
		// don't pass in bad arguments
		void updatePosition(double time_elapsed) {
			// old velocity values 
			std::vector<double> unupdated = velocity;
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
		void updateAcceleration(double mass, std::vector<double> newtons) {
			//f = ma -> a = f/m
			for (int i = 0; i < 3; i++) {
				acceleration[i] = newtons[i] / mass;
			}
		}

		void setPosition(std::vector<double> p) { position = p; }
		std::vector<double> getPosition() { return position; }

		void setVelocity(std::vector<double> v) { velocity = v; }
		std::vector<double> getVelocity() { return velocity; }

		void setAcceleration(std::vector<double> a) { acceleration = a; }
		std::vector<double> getAcceleration() { return acceleration; }

};

#endif
