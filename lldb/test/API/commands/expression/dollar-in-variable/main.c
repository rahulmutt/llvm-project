// Make sure we correctly handle $ in variable names.

int main() {
  // Some variables that might conflict with our variables below.
  int __lldb_expr_result = 2;
  int $$foo = 1;
  int R0 = 2;

  // Some variables with dollar signs that should work (and shadow
  // any built-in LLDB variables).
  int $__lldb_expr_result = 11;
  int $foo = 12;
  int $R0 = 13;
  int $0 = 14;

  //%self.expect_expr("$__lldb_expr_result", result_type="int", result_value="11")
  //%self.expect_expr("$foo", result_type="int", result_value="12")
  //%self.expect_expr("$R0", result_type="int", result_value="13")
  //%self.expect("expr int $foo = 123", error=True, substrs=["declaration conflicts"])
  //%self.expect_expr("$0", result_type="int", result_value="11")
  return 0;
}
