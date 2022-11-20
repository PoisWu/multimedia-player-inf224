import javax.swing.*;

import java.awt.BorderLayout;
import java.awt.event.*;

import  java.io.*;
import java.net.*;

public class Media_interface extends JFrame{

    private static final long serialVersionUID = 1L;
    JButton getbutton;
    JButton closebutton;
    JButton playbutton;
    JTextArea text_area;
    JTextField textField;
    JMenuItem menuitem_getbutton;
    JMenuItem menuitem_playbutton;
    JMenuItem menuitem_closebutton;

    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;
    static Client client;
    Socket sock;
    BufferedReader input;
    BufferedWriter output;
  


    public static void main(String argv[]){
       
        new Media_interface(argv);
        
       
    }
    //
    public Media_interface(String argv[]){
        
        String host = DEFAULT_HOST;
        int port = DEFAULT_PORT;
        if (argv.length >=1) host = argv[0];
        if (argv.length >=2) port = Integer.parseInt(argv[1]);
        
        
        try {
            client = new Client(host, port);
        }
        catch (Exception e) {
            System.err.println("Client: Couldn't connect to "+host+":"+port);
            System.exit(1);
        }
        
        // Connection okay 
        System.out.println("Client connected to "+host+":"+port);

        // pour lire depuis la console
        
        // BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
        
        // Here is where it sends the request 
        // while (true) {
        //     System.out.print("Request: ");
        //     try {
        //         String request = cin.readLine();
        //         String response = client.send(request);
        //         System.out.println("Response: " + response);
        //     }
        //     catch (java.io.IOException e) {
        //         System.err.println("Client: IO error");
        //         return;
        //     }
        // }

        // Bottom part 

        JPanel panel_bottom = new JPanel();

 
        
        // Menu part
        JMenu menu = new JMenu("Action");

        //JMenuItems
        menuitem_getbutton = new JMenuItem("Search");
        menuitem_playbutton = new JMenuItem("Play");
        menuitem_closebutton = new JMenuItem("Close");

        menuitem_getbutton.addActionListener(new GETaction());
        menuitem_playbutton.addActionListener(new PLAYaction());
        menuitem_closebutton.addActionListener(new CloseListener());

        menu.add(menuitem_getbutton);
        menu.add(menuitem_playbutton);
        menu.add(menuitem_closebutton);


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
        textField = new JTextField("");
        textField.setColumns(30);
        panel_bottom.add(textField);

        panel_bottom.add(getbutton = new JButton("Search"));
        panel_bottom.add(playbutton = new JButton("Play"));
        panel_bottom.add(closebutton = new JButton("Close"));

        
        closebutton.addActionListener(new CloseListener());
        getbutton.addActionListener(new GETaction());
        playbutton.addActionListener(new PLAYaction());
       // add(BorderLayout.SOUTH, panel_bottom);


        // Frame Part 
        setTitle("Mutimedia");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }
    String parseResult(String result){
        String response = result.replace(";", "\n");
        return response;
    }

    class GETaction implements ActionListener{
        public void actionPerformed(ActionEvent e){
            String response = client.send("GET "+ textField.getText());
            response = parseResult(response);
            text_area.append(response);
        }
    }
    
    class PLAYaction implements ActionListener{
        public void actionPerformed(ActionEvent e){
            String response = client.send("PLAY "+ textField.getText());
            response = parseResult(response);
            text_area.append(response);
        }
    
    }
    class CloseListener implements ActionListener{
        public void actionPerformed(ActionEvent e){
            System.exit(0);
        }
    }
    static class Client{
      
        private Socket sock;
        private BufferedReader input;
        private BufferedWriter output;

        Client(String host, int port) throws UnknownHostException, IOException {
            try {
                this.sock = new java.net.Socket(host, port);
            }
            catch (java.net.UnknownHostException e) {
                System.err.println("Client: Couldn't find host "+host+":"+port);
                throw e;
            }
            catch (java.io.IOException e) {
                System.err.println("Client: Couldn't reach host "+host+":"+port);
                throw e;
            }
            
            try {
                input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
                output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
            }
            catch (java.io.IOException e) {
                System.err.println("Client: Couldn't open input or output streams");
                throw e;
            }
        }
      
      // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      

        public String send(String request) {
            // Envoyer la requete au serveur
            try {
                request += "\n";  // ajouter le separateur de lignes
                output.write(request, 0, request.length());
                output.flush();
            }
            catch (java.io.IOException e) {
                System.err.println("Client: Couldn't send message: " + e);
                return null;
            }
            
            // Recuperer le resultat envoye par le serveur
            try {
                return input.readLine();
            }
            catch (java.io.IOException e) {
                System.err.println("Client: Couldn't receive message: " + e);
                return null;
            }
        }
    }
}
