
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
 
public class MyFrame{

    private MyFrame() {
        //Create and set up the window.
        JFrame frame = new JFrame("MyFrame");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		

        //Create the menu bar.  Make it have a green background.
        JMenuBar greenMenuBar = new JMenuBar();
        greenMenuBar.setOpaque(true);
        greenMenuBar.setBackground(new Color(154, 165, 127));
        greenMenuBar.setPreferredSize(new Dimension(200, 20));
 
        //Create a yellow label to put in the content pane.
		JButton jButton = new JButton("0");
		jButton.setBackground(new Color(248, 213, 131));
		jButton.setPreferredSize(new Dimension(200, 180));
		
		
        //Set the menu bar and add the label to the content pane.
        frame.setJMenuBar(greenMenuBar);
        frame.getContentPane().add(jButton, BorderLayout.CENTER);
 
        //Display the window.
        frame.pack();
        frame.setVisible(true);
    }
 
    public static void main(String[] args) {
        //Schedule a job for the event-dispatching thread:
        //creating and showing this application's GUI.
		new MyFrame();
    }
}
