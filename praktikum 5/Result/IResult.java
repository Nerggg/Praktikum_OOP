public interface IResult<T, E extends Exception> {

    boolean isOk();

    boolean isErr();

    T unwrap() throws Exception;

    T unwrapOrElse(T defaultValue);

    T unwrapOrThrow(Exception defaultException) throws Exception;
}