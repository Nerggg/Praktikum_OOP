public class Result<T, E extends Exception> implements IResult<T, E> {
    private T data;
    private E error;

    public Result(T data, E error) {
        this.data = data;
        this.error = error;
    }

    public static <T, E extends Exception> Result<T, E> ok(T data) {
        return new Result<T, E>(data, null);
    }

    public static <T, E extends Exception> Result<T, E> err(E error) {
        return new Result<T, E>(null, error);
    }

    public boolean isOk() {
        return data != null;
    }

    public boolean isErr() {
        return error != null;
    }

    public T unwrap() throws Exception {
        if (isOk()) {
            return data;
        } else {
            throw error;
        }
    }

    public T unwrapOrElse(T defaultValue) {
        if (isOk()) {
            return data;
        } else {
            return defaultValue;
        }
    }

    public T unwrapOrThrow(Exception defaultException) throws Exception {
        if (isOk()) {
            return data;
        } else {
            throw defaultException;
        }
    }
}