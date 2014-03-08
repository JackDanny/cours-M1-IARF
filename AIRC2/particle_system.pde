
ParticleSystem ps;

void setup()
{
  size(800, 600, P3D);
  ps = new ParticleSystem(50, new PVector(width/2, height/2));
  smooth(); // make it pretty!
}

void draw()
{
  background(50);
  ps.run();
  ps.addParticle(new PVector(mouseX, mouseY));
  
}

void mousePressed()
{
  println(ps.particle_list.size());
}

// A class describing a particle system.
// We'll use an arraylist to keep track of all the particles 
// we create.

public class ParticleSystem
{
  
  ArrayList particle_list;
  
  ParticleSystem(int num, PVector _loc)
  {
    
    particle_list = new ArrayList();
    for(int i = 0; i < num; i++)
    {
      Particle p = new Particle(_loc.get());
      particle_list.add(p);
    }
    
  }
  
  void run()
  {    
    for(int i = 0; i < particle_list.size(); i++)
    {
      Particle p = (Particle) particle_list.get(i);
      p.tick();
    }
    
    connectivity();
    cleanTheDead();
  }
  
  void connectivity()
  {
    for(int i = 0; i < particle_list.size(); i++)
    {
      Particle p = (Particle) particle_list.get(i);
      
      for(int j = i+1; j < particle_list.size(); j++)
      {
        Particle d = (Particle) particle_list.get(j);
        
        float distance = p.loc.dist(d.loc); 
        //println(distance);
        if((distance < 70)&&(distance>0))
        {
          stroke(255, map(distance, 0, 70, 255, 0));
          line(p.loc.x, p.loc.y, p.loc.z, d.loc.x, d.loc.y, d.loc.z); 
        }
        
      }
    }
  }
  
  void cleanTheDead()
  {
    for(int i = particle_list.size()-1; i > 0; i--)
    {
      Particle p = (Particle) particle_list.get(i);
      if(p.isDead()) particle_list.remove(i);
    }
  }
  
  void addParticle(PVector _loc)
  {
    particle_list.add(new Particle(_loc.get()));
  }
}
// A class describing a particle:
// location, velocity, and acceleration
// timer - track how old the particle is
// r - the radius of the particle

public class Particle
{
  PVector loc;
  PVector vel;
  PVector acc;
  
  int timer;
  float r;
  
  Particle(PVector _loc)
  {
    loc = _loc;
    vel = new PVector(random(-2, 2), random(-2, 2));
    acc = new PVector(0, random(0.005, 0.02));
    
    timer = 100;
    r = 20;
  }
  
  void tick()
  {
    vel.add(acc);
    loc.add(vel);
    
    timer -= 0.5;
    
    display();
  }
  
  void display()
  {
    fill(255, map(timer, 0, 100, 0, 255));
    stroke(255);
    
    ellipse(loc.x, loc.y, map(timer, 0, 100, 0, 50), map(timer, 0, 100, 0, 50));    
  }
  
  boolean isDead()
  {
    return timer <= 0 ? true : false;
  }
}
