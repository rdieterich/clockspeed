# Setup build environment
#env = Environment(CCFLAGS = '-O2 -std=c99 -D_POSIX_C_SOURCE=200809L -Wall')
env = Environment(CCFLAGS = '-O2 -std=c99 -D_GNU_SOURCE -Wall -DHASRDTSC=1')

# Production rules for libraries
env.Library('error', ['error.c', 'error_str.c'])

env.Library('fs', [
    'fmt_str.c',
    'fmt_uint.c',
    'fmt_uint0.c',
    'fmt_ulong.c',
    'scan_ulong.c'
])

env.Library('open', ['open_read.c', 'open_trunc.c', 'open_write.c'])

env.Library('str', [
    'str_len.c',
    'str_diff.c',
    'byte_diff.c',
    'byte_chr.c',
    'byte_copy.c',
    'byte_cr.c',
    'byte_zero.c'
])

env.Library('strerr', ['strerr_sys.c', 'strerr_die.c'])

env.Library('substdio', [
    'substdio.c',
    'substdi.c',
    'substdo.c',
    'subfderr.c',
    'substdio_copy.c'
])

env.Library('tai', [
    'tai_pack.c', 'tai_unpack.c', 'taia_add.c', 'taia_half.c', 'taia_less.c',
    'taia_now.c', 'taia_pack.c', 'taia_sub.c', 'taia_unpack.c',
    'leapsecs_add.c', 'leapsecs_init.c', 'leapsecs_read.c'])

# Production rules for objects
env.Object('ip.c')
env.Object('auto_home.c')

# Production rules for programs
env.Program('auto-str.c',
    LIBS=['substdio', 'error', 'str'],
    LIBPATH='.')

env.Program('clockview.c',
    LIBS=['strerr', 'substdio', 'error', 'str', 'fs'],
    LIBPATH='.')

env.Program(['sntpclock.c', 'ip.o'],
    LIBS=['tai', 'strerr', 'substdio', 'error', 'str', 'fs'],
    LIBPATH='.')

env.Program(['taiclock.c', 'ip.o'],
    LIBS=['tai', 'strerr', 'substdio', 'error', 'str', 'fs'],
    LIBPATH='.')
    
env.Program('taiclockd.c',
    LIBS=['tai', 'strerr', 'substdio', 'error', 'str'],
    LIBPATH='.')

env.Program('clockadd.c',
    LIBS=['strerr', 'substdio', 'error', 'str'],
    LIBPATH='.')

env.Program(['clockspeed.c', 'auto_home.o'],
    LIBS=['open', 'error', 'str', 'fs'],
    LIBPATH='.')
