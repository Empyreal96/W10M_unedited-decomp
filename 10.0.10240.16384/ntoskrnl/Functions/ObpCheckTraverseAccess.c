// ObpCheckTraverseAccess 
 
int __fastcall ObpCheckTraverseAccess(int a1, int a2, int a3, int a4, char a5, int *a6)
{
  int v7; // r5
  int v8; // r0
  int v9; // r4
  int v10; // r0
  _DWORD *v11; // r5
  char v13[4]; // [sp+18h] [bp-20h] BYREF
  int v14; // [sp+1Ch] [bp-1Ch] BYREF
  _DWORD *v15; // [sp+20h] [bp-18h] BYREF
  int v16[5]; // [sp+24h] [bp-14h] BYREF

  v15 = 0;
  v16[0] = 0;
  v7 = ObTypeIndexTable[*(unsigned __int8 *)(a1 - 12) ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
  v8 = ObpGetObjectSecurity(a1, (unsigned int *)&v14, v13, a5);
  if ( v8 >= 0 )
  {
    if ( SeFastTraverseCheck(v14, a3, 2) )
    {
      v9 = 1;
    }
    else
    {
      SeLockSubjectContext((_DWORD *)(a3 + 28));
      v10 = SeAccessCheck(v14, a3 + 28, 1, 2, 0, (int)&v15, v7 + 52, a5, (int)v16, (int)a6);
      v11 = v15;
      v9 = v10;
      if ( v15 )
      {
        SeAppendPrivileges(a3, v15);
        ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)v11);
      }
      SeUnlockSubjectContext((_DWORD *)(a3 + 28));
    }
    ObReleaseObjectSecurity(v14, (unsigned __int8)v13[0]);
  }
  else
  {
    v9 = 0;
    *a6 = v8;
  }
  return v9;
}
