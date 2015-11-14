<meta charset='utf-8'/>
<html>
	<head>
		<title>static - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


        <a name="TOC-in-type_scope-indicates-that-a-member-function-field-or-property-is-not-an-instance-member-but-one-that-becomes-part-of-the-type-object-itself">
        </a>
        <span style="line-height:1.6;font-size:10pt;background-color:transparent">
            in type_scope, indicates that a member function, field, or property is not an instance member, but one that becomes part of the type object itself
        </span>
    </h4>
    <div>
        <br>
        </br>
    </div>
    <div>
        Example:
    </div>
    <div>
    </div>
    <div class="sites-codeblock sites-codesnippet-block">
        <div>
            <code>
                &lt;Type&gt; Dog := type {
            </code>
        </div>
        <div>
            <span>
                <code>
                        &lt;String&gt; name;
                </code>
            </span>
            <br>
            </br>
        </div>
        <div>
            <span>
                <span>
                    <code>
                            &lt;Date&gt; birth_date;
                    </code>
                </span>
                <br>
                </br>
            </span>
        </div>
        <div>
            <span>
                <span>
                    <span>
                        <code>
                                static &lt;String&gt; binomial_nomenclature := "Canis Familiaris";
                        </code>
                    </span>
                    <br>
                    </br>
                </span>
            </span>
        </div>
        <div>
            <code>
                };
            </code>
        </div>
    </div>



		<?php require('../../footer.php') ?>
	</body>
</html>