// IoGetRequestorProcessId 
 
int __fastcall IoGetRequestorProcessId(int a1)
{
  int v1; // r0
  int result; // r0

  v1 = IoGetRequestorProcess(a1);
  if ( v1 )
    result = *(_DWORD *)(v1 + 176);
  else
    result = 0;
  return result;
}
