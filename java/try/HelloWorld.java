import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class HelloWorld{     
    public HelloWorld() {
        JFrame frame = new JFrame("HelloWorld");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 

        JMenuBar greenMenuBar = new JMenuBar();
        greenMenuBar.setOpaque(true);
        greenMenuBar.setBackground(new Color(154, 165, 127)); //三原色调配出目标颜色
        greenMenuBar.setPreferredSize(new Dimension(200, 20)); //设定MenuBar的大小  

        JLabel yellowLabel = new JLabel();
        yellowLabel.setOpaque(true);
        yellowLabel.setBackground(new Color(248, 213, 131));
        yellowLabel.setPreferredSize(new Dimension(200, 180)); 

        JButton jb = new JButton("press me");
        jb.setOpaque(true);
        jb.setBackground(new Color(0, 0, 255));
        jb.setPreferredSize(new Dimension(50, 20)); 

        frame.setJMenuBar(greenMenuBar); //将menuBar添加到JFrame容器中
        frame.getContentPane().add(yellowLabel, BorderLayout.CENTER); //将yellowLable添加到ContentPane中。
        frame.getContentPane().add(jb, BorderLayout.CENTER);
        frame.pack(); //调整窗口至最佳大小
        frame.setVisible(true);
    } 
    public static void main(String[] args) {   
        new HelloWorld();     
    }
} 