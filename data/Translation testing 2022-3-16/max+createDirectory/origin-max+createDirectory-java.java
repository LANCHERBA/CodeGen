public static int max(int a, int b){
    return a > b ? a : b;
}

public static void createDirectory(Path path) throws IOException{
    if(!Files.exists(path)){
        Files.createDirectories(path);
    }
}