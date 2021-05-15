// PipQueryBindingResolution 
 
int *__fastcall PipQueryBindingResolution(_DWORD *a1)
{
  int v2; // r4
  int *v3; // r5
  int *v4; // r8
  int *v5; // r9
  unsigned __int16 *v6; // r1
  unsigned __int16 *v7; // r3
  int v8; // r3
  unsigned __int16 *v10; // [sp+0h] [bp-20h]

  v2 = 0;
  if ( *a1 )
  {
    if ( *a1 == 1 )
    {
      v3 = (int *)PiDependencyNodeListHead;
LABEL_4:
      while ( v3 != &PiDependencyNodeListHead )
      {
        v4 = v3;
        v5 = (int *)v3[7];
        v3 = (int *)*v3;
        if ( v5 != v4 + 7 )
        {
          v6 = (unsigned __int16 *)a1[1];
          v10 = v6;
          while ( 1 )
          {
            v7 = (unsigned __int16 *)v5;
            v5 = (int *)*v5;
            if ( RtlEqualUnicodeString(v7 + 4, v6, 1) )
              return v4;
            v6 = v10;
            if ( v5 == v4 + 7 )
              goto LABEL_4;
          }
        }
      }
    }
  }
  else
  {
    v8 = a1[1];
    if ( v8 )
      v2 = *(_DWORD *)(*(_DWORD *)(v8 + 176) + 44);
    else
      v2 = 0;
  }
  return (int *)v2;
}
