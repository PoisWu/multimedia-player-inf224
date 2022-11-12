import javax.swing.*;

import java.awt.BorderLayout;
import java.awt.event.*;
public class Media_interface extends JFrame{

    // One zone multi-line text (JTextArea) taille suffisante
    // JScrollPane
    // Three boutons(Jbutton), while the activatiion, ajoute une lighe de texte
    // à la zone de texte, derier bouton termine l'application.(méthode
    // exit(int) 
    // 
    //
    private static final long serialVersionUID = 1L;
    JButton button_add_text1;
    JButton button_terminate;
    JButton button_add_text2;
    JTextArea text_area;

    public static void main(String argv[]){
        new Media_interface();
    }
    //
    public Media_interface(){

        JPanel panel_bottom = new JPanel();

        panel_bottom.add(button_add_text1 = new JButton("add_text1"));
        panel_bottom.add(button_terminate = new JButton("terminate"));
        panel_bottom.add(button_add_text2 = new JButton("add_text2"));
        
        button_terminate.addActionListener(new CloseListener());
        button_add_text1.addActionListener(new add_text1Listener());
        button_add_text2.addActionListener(new add_text2Listener());
        
        
        
        text_area = new JTextArea(10,10);
        JScrollPane scroll = new JScrollPane(text_area);
        scroll.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
        add(BorderLayout.CENTER,scroll);
        add(BorderLayout.SOUTH, panel_bottom);

        setTitle("Mutimedia");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    class add_text1Listener implements ActionListener{
        public void actionPerformed(ActionEvent e){
            text_area.append("Text1\n");
        }
    }
    
    class add_text2Listener implements ActionListener{
        public void actionPerformed(ActionEvent e){
            text_area.append("Text2\n");
        }
    
    }
    class CloseListener implements ActionListener{
        public void actionPerformed(ActionEvent e){
            System.exit(0);
        }
    }
}
