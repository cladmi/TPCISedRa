Validate on CI
==============

At this point you have a your python project packaged with setup.py and tests
running managed by tox. This means that running your tests only need to run:

    tox

All the dependencies will be installed automatically.



Running your first test on CI
-----------------------------

Create your job with 'New Item' button on the left menu.

For Python create a 'Freestyle project' and put a name without spaces, it always
brings errors in scripts to have path with spaces.

Then go to Configure


### Git configuration ###

Source Code Management -> Git

Put the anonymous git url of the repository `<ADD_URL_HERE>` and select your
branch name `*/branch_name`.

### Build Step ###

Add build step: 'Execute Shell' and execute:

    cd python/
    tox

Save the configuration.



### Running test ###

What is the result ?
See 'Console Output' to see the script execution.


Fixing this the python way
--------------------------

As seen, 'tox' is not installed on the build machine. It can either be installed
manually or as a step of the integration process. The last solution is more in
the process of 'integration' but sometimes you don't have the choice.


Remove the build step and replace it with 'Virtualenv Builder'.
This puts the code execution in a separated python environment for the build.


Now as first step, install your `tox` dependency:

    pip install --quiet --upgrade tox

    cd python
    tox


Save and build, it should be a successful build.

See the build output, you can see tests/coverage/pylint/pep8 text results.


Adding Build feedback
---------------------

A big value of Jenkins is the ability to nicely present your tests results.

The tools used to run tests and code quality where selected because
they have output files compatible with Jenkins plugins.

> Note: This selection may look restrictive, but it also means that the tools
> are indeed used by many developers and that it is not only a one man written
> test script.


* `nosetests` outputs as a JUnit compatible XML: `nosetests.xml`
* `nose-xcover` outputs coverage compatible with cobertura: `coverage.xml`
* `pylint` and `pep8` output is recognized by 'warnings' and 'violations' plugins.


These output parsing is managed in 'Add post-build action'.

> Maybe print the real plugins names here


### Add tests results feedback ###

Step `Publish JUnit test result report`

Test report xml: `**/*tests.xml` to scan for all files ending with 'tests.xml'


### Add coverage feedback ###

Step `Publish Cobertura Coverage Report`

Cobertura xml report pattern: `**/coverage.xml` to scan for all 'coverage.xml' files.


As source files are not based at root directory Cobertura fails to locate source
files. A solution is to create a symlink to the source directory:

Add a build step 'Execute shell' with:

    # Hack to help cobertura find source files
    ln  -nfs Src/python/tp_ci_sed  tp_ci_sed


### Add code quality output ###

Step `Scan for compiler warnings`

Scan console log add two parsers, one for `pylint` and another for `pep8`.


### Code review by ChuckNorris ###

Step `Activate Chuck Norris` it displays you Chuck Norris facts and a picture of
Chuck adapted to your build result (seems like the picture is not displayed?)


Save configuration.


Analyze build output
--------------------

Build the project two times to get a nice displayed output. Plugins need
multiple builds to create graphs.


### Coverage Report ###

Click on Coverage Report, you can then see per file coverage output.


### Pylint/PEP8 ###

? The per file output didn't work? Why?



Further steps
-------------

# TODO

Automatically run the build:

 * Never: you only run it manually (not recommended)
 * Periodically: Every night at 3AM may be enough if your code moves slowly
 * At each commit: with repository polling/ with git hook (see how...)

Send mails on build failure:

 * Howto do that?


Improvements
------------

* Try fixing all your code to get perfect results outputs.
* Use tox to run tests on python3 also and make your code compatible with.


