package server.exceptions;

public class InterlocuteurException extends Exception {

    private int code;

    public InterlocuteurException(int code) {
        super();
        this.code = code;
    }

    public InterlocuteurException(String message, Throwable cause, int code) {
        super(message, cause);
        this.code = code;
    }

    public InterlocuteurException(String message, int code) {
        super(message);
        this.code = code;
    }

    public InterlocuteurException(Throwable cause, int code) {
        super(cause);
        this.code = code;
    }

    public int getCode() {
        return this.code;
    }
}
