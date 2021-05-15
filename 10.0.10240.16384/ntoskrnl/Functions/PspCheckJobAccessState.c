// PspCheckJobAccessState 
 
int __fastcall PspCheckJobAccessState(_DWORD *a1, int a2)
{
  int result; // r0
  char v4[4]; // [sp+18h] [bp-20h] BYREF
  int v5; // [sp+1Ch] [bp-1Ch] BYREF
  int v6; // [sp+20h] [bp-18h] BYREF
  char v7[20]; // [sp+24h] [bp-14h] BYREF

  result = 0;
  if ( (*(_DWORD *)(a2 + 188) & 1) == 0 && (*a1 & 1) == 0 )
  {
    result = ObpGetObjectSecurity(a2, (unsigned int *)&v5, v4, 0);
    v6 = result;
    if ( result >= 0 )
    {
      SeAccessCheck(v5, (int)(a1 + 1), 0, 512, 0, 0, PsProcessType + 52, 1, (int)v7, (int)&v6);
      ObReleaseObjectSecurity(v5, (unsigned __int8)v4[0]);
      result = v6;
    }
  }
  return result;
}
