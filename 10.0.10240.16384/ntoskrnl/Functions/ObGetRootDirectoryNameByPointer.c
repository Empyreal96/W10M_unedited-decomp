// ObGetRootDirectoryNameByPointer 
 
int __fastcall ObGetRootDirectoryNameByPointer(int a1, unsigned __int16 *a2)
{
  int v3; // r4
  int v4; // r0
  unsigned __int16 *v5; // r6
  int v6; // r0
  unsigned __int16 v7; // r3
  int v9; // [sp+8h] [bp-20h] BYREF
  int v10; // [sp+Ch] [bp-1Ch] BYREF
  int v11[6]; // [sp+10h] [bp-18h] BYREF

  if ( a2 )
  {
    v3 = PsGetSiloObjectByPointer(a1, &ObpDirectoryObjectType, v11);
    if ( v3 < 0 )
      return v3;
    v3 = ObQueryNameStringMode(v11[0], 0, 0, &v9, 0);
    if ( v3 != -1073741820 )
    {
LABEL_15:
      ObfDereferenceObject(v11[0]);
      return v3;
    }
    v9 += 8;
    v4 = ExAllocatePoolWithTag(1, v9, 1833853519);
    v5 = (unsigned __int16 *)v4;
    if ( !v4 )
    {
      v3 = -1073741670;
      goto LABEL_15;
    }
    v3 = ObQueryNameStringMode(v11[0], v4, v9, &v10, 0);
    if ( v3 >= 0 )
    {
      if ( *((_DWORD *)a2 + 1) )
      {
        if ( a2[1] < (unsigned int)v5[1] )
        {
          v3 = -1073741789;
          goto LABEL_13;
        }
      }
      else
      {
        v10 += *a2;
        v6 = ExAllocatePoolWithTag(1, v10, 1833853519);
        *((_DWORD *)a2 + 1) = v6;
        if ( !v6 )
          goto LABEL_13;
        v7 = v10;
        *a2 = 0;
        a2[1] = v7;
      }
      RtlCopyUnicodeString(a2, v5);
    }
LABEL_13:
    ExFreePoolWithTag((unsigned int)v5);
    goto LABEL_15;
  }
  return -1073741584;
}
