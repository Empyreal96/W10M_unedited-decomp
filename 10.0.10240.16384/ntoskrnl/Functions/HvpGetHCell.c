// HvpGetHCell 
 
int __fastcall HvpGetHCell(int a1)
{
  int v1; // r0
  int result; // r0

  v1 = (*(int (**)(void))(a1 + 4))();
  if ( v1 )
    result = v1 - 4;
  else
    result = 0;
  return result;
}
