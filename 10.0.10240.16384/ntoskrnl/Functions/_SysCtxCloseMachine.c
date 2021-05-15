// _SysCtxCloseMachine 
 
int __fastcall SysCtxCloseMachine(_DWORD *a1)
{
  if ( a1[1] )
    ZwClose();
  if ( a1[3] )
    ZwClose();
  if ( a1[4] )
    ZwClose();
  if ( a1[6] )
    ZwClose();
  if ( a1[5] )
    ZwClose();
  ExFreePoolWithTag((unsigned int)a1);
  return 0;
}
