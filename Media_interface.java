import javax.swing.*;

import java.awt.BorderLayout;
import java.awt.event.*;
public class Media_interface extends JFrame{
    // Task 1
    // One zone multi-line text (JTextArea) taille suffisante
    // JScrollPane
    // Three boutons(Jbutton), while the activatiion, ajoute une lighe de texte
    // à la zone de texte, derier bouton termine l'application.(méthode
    // exit(int) 
    // 
    // Task 2
    // Add JMenuBar/ JMenu/ JToolBar.
    // JMenuBar, add via the methode setMenuBar()
    // JMenu, contien les même boutons que Task1
    // JToolBar: zone nore de la fenetre principale. contient les même boutons que Ttask1  
    private static final long serialVersionUID = 1L;
    JButton button_add_text1;
    JButton button_terminate;
    JButton button_add_text2;
    JTextArea text_area;
    JMenuItem menuitem_add_text1;
    JMenuItem menuitem_add_text2;
    JMenuItem menuitem_terminate;

    public static void main(String argv[]){
        new Media_interface();
    }
    //
    public Media_interface(){

        // Bottom part 
        JPanel panel_bottom = new JPanel();

        panel_bottom.add(button_add_text1 = new JButton("add_text1"));
        panel_bottom.add(button_terminate = new JButton("terminate"));
        panel_bottom.add(button_add_text2 = new JButton("add_text2"));
        
        button_terminate.addActionListener(new CloseListener());
        button_add_text1.addActionListener(new add_text1Listener());
        button_add_text2.addActionListener(new add_text2Listener());
        
        // Menu part
        JMenu menu = new JMenu("File");

        //JMenuItems
        menuitem_add_text1 = new JMenuItem("Add Text 1");
        menuitem_add_text2 = new JMenuItem("Add Text 2");
        menuitem_terminate = new JMenuItem("terminate");

        menuitem_add_text1.addActionListener(new add_text1Listener());
        menuitem_add_text2.addActionListener(new add_text2Listener());
        menuitem_terminate.addActionListener(new CloseListener());

        menu.add(menuitem_add_text1);
        menu.add(menuitem_add_text2);
        menu.add(menuitem_terminate);


        // menubar part
        JMenuBar menubar = new JMenuBar();
        menubar.add(menu);
        setJMenuBar(menubar);
        


        // Toolbar part
        JToolBar toolbar = new JToolBar();

        toolbar.add(panel_bottom);
        add(BorderLayout.NORTH, toolbar);
        
        
        // Text Area Part
        text_area = new JTextArea(10,10);
        JScrollPane scroll = new JScrollPane(text_area);
        scroll.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
        add(BorderLayout.CENTER,scroll);
       // add(BorderLayout.SOUTH, panel_bottom);


        // Frame Part 
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
