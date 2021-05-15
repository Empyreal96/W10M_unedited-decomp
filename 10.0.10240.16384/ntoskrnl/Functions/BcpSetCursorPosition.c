// BcpSetCursorPosition 
 
int __fastcall BcpSetCursorPosition(__int64 a1, int *a2)
{
  *(_QWORD *)&BcpCursor = a1;
  if ( a2 )
    dword_653574 = *a2;
  return a1;
}
