// ObClearProcessHandleTable 
 
int __fastcall ObClearProcessHandleTable(int a1)
{
  int result; // r0

  result = ObReferenceProcessHandleTable(a1);
  if ( result )
    result = sub_7BFF30();
  return result;
}
