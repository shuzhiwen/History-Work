import java.awt.*;
import java.awt.event.*;

class ButtonListener implements ActionListener{
	     Button b;
		 private int numClicks=0;
		 
		 public ButtonListener(Button b1){
			b = b1;
		 }
		 
		 public void actionPerformed(ActionEvent e) {
                numClicks++;
                //text.setText("Button Clicked " + numClicks + " times");
				b.setLabel(numClicks+"");
        }
}

public class AL extends Frame implements WindowListener{
        //TextField text = new TextField(20);
        Button b;
        //private int numClicks = 0;

        public static void main(String[] args) {
                AL myWindow = new AL("My first window");
                myWindow.setSize(350,100);
                myWindow.setVisible(true);
        }

        public AL(String title) {

                super(title);
                setLayout(new FlowLayout());
                addWindowListener(this);
                b = new Button("0");
				b.setPreferredSize(new Dimension(100, 40));
                add(b);
                //add(text);
				ButtonListener bl = new ButtonListener(b);
                b.addActionListener(bl);
        }



        public void windowClosing(WindowEvent e) {
                dispose();
                System.exit(0);
        }

        public void windowOpened(WindowEvent e) {}
        public void windowActivated(WindowEvent e) {}
        public void windowIconified(WindowEvent e) {}
        public void windowDeiconified(WindowEvent e) {}
        public void windowDeactivated(WindowEvent e) {}
        public void windowClosed(WindowEvent e) {}

}