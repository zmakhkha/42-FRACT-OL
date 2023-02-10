# FRACT-OL


<img src="Subject/en.subject_page-0001.jpg"/>


<img src="Subject/en.subject_page-0002.jpg"/>



<img src="Subject/en.subject_page-0003.jpg"/>



<img src="Subject/en.subject_page-0004.jpg"/>



<img src="Subject/en.subject_page-0005.jpg"/>



<img src="Subject/en.subject_page-0006.jpg"/>



<img src="Subject/en.subject_page-0007.jpg"/>



<img src="Subject/en.subject_page-0008.jpg"/>


<img src="Subject/en.subject_page-0009.jpg"/>


<img src="Subject/en.subject_page-0010.jpg"/>


<img src="Subject/en.subject_page-0011.jpg"/>




# Introduction to Fractals

Fractals are mathematical objects that have the property of self-similarity at different scales. They are often characterized by their repeating patterns and intricate shapes. Some famous examples of fractals include the Mandelbrot set and the Julia sets ...


## Equations of Fractals

Here are the equations for some popular fractals:


### Mandelbrot Set

The equation for the Mandelbrot set is:

Z_{n+1} = Z_n^2 + C


where `Z_0 = 0` and `C` is a constant.

### Julia Sets

The equation for a Julia set is similar to the Mandelbrot set, with a fixed value for `C`:

Z_{n+1} = Z_n^2 + C


where `Z_0` can be any complex number and `C` is a constant.

### Burning Ship Fractal

The equation for the Burning Ship fractal is:

Z_{n+1} = abs(Z_n)^2 + C

Z_{n+1} = abs(Z_n)^2 + C


where `Z_0 = 0` and `C` is a constant.

### Tricorn Fractal

The equation for the Tricorn fractal is:

Z_{n+1} = conjugate(Z_n^2) + C


where `Z_0 = 0` and `C` is a constant. The `conjugate` function returns the complex conjugate of a complex number.


## Coloring Functions

In order to create an image of a fractal, it is necessary to iterate the equation for each pixel in the image. To do this, we use a relative function to determine if a point `C` belongs to the fractal set. If the magnitude of `Z_n` exceeds a certain threshold, it is considered to be outside of the set and is colored accordingly. If the magnitude remains below the threshold after a certain number of iterations, it is considered to be inside the set and is also colored.


# Conclusion

Fractals are fascinating mathematical objects that are capable of generating intricate patterns and shapes. By iterating the equations for different fractals and using relative functions, it is possible to generate beautiful images of these sets. Whether you are a math enthusiast or just enjoy exploring the world of computer graphics, learning about fractals is a fun and rewarding experience.

# Examples


## Mandelbrot set

<img src="Examples/1.png"/>
<img src="Examples/2.png"/>
<img src="Examples/3.png"/>
<img src="Examples/4.png"/>

## Julia set



<img src="Examples/5.png"/>
<img src="Examples/6.png"/>


## Burning ship set


<img src="Examples/7.png"/>
<img src="Examples/8.png"/>
<img src="Examples/10.png"/>

## Tricorn set


<img src="Examples/11.png"/>
<img src="Examples/12.png"/>
<img src="Examples/13.png"/>
<img src="Examples/14.png"/>
<img src="Examples/15.png"/>
