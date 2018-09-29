import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class HelloWorld{     
    public HelloWorld() {
        JFrame frame = new JFrame("HelloWorld");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 

        JMenuBar greenMenuBar = new JMenuBar();         
        greenMenuBar.setBackground(new Color(154, 165, 127)); //三原色调配出目标颜色
        greenMenuBar.setPreferredSize(new Dimension(200, 20)); //设定 MenuBar 的大小  

        JLabel yellowLabel = new JLabel();
        yellowLabel.setBackground(new Color(248, 213, 131));
        yellowLabel.setPreferredSize(new Dimension(200, 180)); 

        JButton jb = new JButton("press me");
        jb.setPreferredSize(new Dimension(50, 20)); 

        frame.setJMenuBar(greenMenuBar); //将 menuBar 添加到 JFrame 容器中
        frame.getContentPane().add(yellowLabel, BorderLayout.CENTER); //将 yellowLable 添 加到 ContentPane 中。
        frame.getContentPane().add(jb, BorderLayout.CENTER);
        frame.pack(); //调整窗口至最佳大小
        frame.setVisible(true);
    } 
    public static void main(String[] args) {   
        new HelloWorld();     
    }

} 